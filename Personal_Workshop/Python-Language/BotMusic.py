import discord
from discord.ext import commands
import youtube_dl

# Define the intents your bot will use
intents = discord.Intents.default()
intents.message_content = True  # Enable the intent to read message content

# Set up the bot with a command prefix and intents
bot = commands.Bot(command_prefix='!', intents=intents)

# Ensure FFmpeg is installed and available in your PATH
ytdl_format_options = {
    'format': 'bestaudio/best',
    'postprocessors': [{
        'key': 'FFmpegExtractAudio',
        'preferredcodec': 'mp3',
        'preferredquality': '192',
    }],
}

ffmpeg_options = {
    'options': '-vn',
}

ytdl = youtube_dl.YoutubeDL(ytdl_format_options)

class YTDLSource(discord.PCMVolumeTransformer):
    def __init__(self, source, *, data, volume=0.5):
        super().__init__(source, volume)
        self.data = data
        self.title = data.get('title')
        self.url = data.get('url')

    @classmethod
    async def from_url(cls, url, *, loop=None, stream=False):
        loop = loop or asyncio.get_event_loop()
        data = await loop.run_in_executor(None, lambda: ytdl.extract_info(url, download=not stream))
        filename = data['url'] if stream else ytdl.prepare_filename(data)
        return cls(discord.FFmpegPCMAudio(filename, **ffmpeg_options), data=data)

@bot.event
async def on_ready():
    print(f'Logged in as {bot.user}')

@bot.command(name='join')
async def join(ctx):
    if not ctx.message.author.voice:
        await ctx.send("You are not connected to a voice channel.")
        return
    else:
        channel = ctx.message.author.voice.channel
    await channel.connect()

@bot.command(name='play')
async def play(ctx, url):
    async with ctx.typing():
        player = await YTDLSource.from_url(url, loop=bot.loop)
        ctx.voice_client.play(player, after=lambda e: print(f'Player error: {e}') if e else None)
    await ctx.send(f'Now playing: {player.title}')

@bot.command(name='leave')
async def leave(ctx):
    await ctx.voice_client.disconnect()

@bot.command(name='stop')
async def stop(ctx):
    ctx.voice_client.stop()

# Replace 'YOUR_BOT_TOKEN' with your bot's token
bot.run('a')