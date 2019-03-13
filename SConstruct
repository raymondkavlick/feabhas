# ----------------------------------------------------------------------------
#
Help("""
Type: 'scons' to build the project
      'scons --rtos' to build with the RTOS / FeabhOS enabled
      'scons -c' to clean
""")

# ----------------------------------------------------------------------------
# Project name - this is the name of the 
# output (.hex/.elf) file
#
proj_name = 'C++11-501'

# ----------------------------------------------------------------------------
# Output (variant) directory
#
vdir = 'build/debug/'

# ----------------------------------------------------------------------------
# build with `scons --rtos` for debug.
#
AddOption(
    '--rtos',
    action  = 'store_true',
    help    = 'rtos build',
    default = False)

# ----------------------------------------------------------------------------
# Cross-compiler set-up.  This configuration assumes the cross-compiler
# is in the PATH.  If not, you will have to hard-code the compiler path; for
# example:
# 
# import os
# path = [ '/bin', '/usr/bin', '/usr/local/gcc-arm-none-eabi-7-2017-q4-major/bin' ]
# env = Environment(ENV = { 'PATH' : path })
# 
import os
env = Environment( ENV = os.environ )

env.Replace(AS         = "arm-none-eabi-as")
env.Replace(AR         = "arm-none-eabi-ar")
env.Replace(CC         = "arm-none-eabi-gcc")
env.Replace(CXX        = "arm-none-eabi-g++")
env.Replace(LINK       = "arm-none-eabi-g++")                # predefined is 'arm-none-eabi-gcc'
env.Replace(OBJCOPY    = "arm-none-eabi-objcopy")
env.Replace(PROGSUFFIX = ".elf")
env.Replace(RANLIB     = "arm-none-eabi-ranlib")

# ----------------------------------------------------------------------------
# Processor-specific compiler flags
#
cortex_m4_flags = [
    '-mcpu=cortex-m4',
    '-mthumb',
    '-mfloat-abi=soft',
    ]

# ----------------------------------------------------------------------------
# Global macro definitions
#
env.Append(CPPDEFINES = [
    'DEBUG',
    'USE_FULL_ASSERT',
    'STM32F407xx',
    'TRACE',
    'OS_USE_TRACE_SEMIHOSTING_DEBUG',
    'OS_USE_TRACE_SEMIHOSTING_STDOUT',
    'OS_USE_SEMIHOSTING',           # see linker flags required
])

if GetOption('rtos'):
    env.Append(CPPDEFINES = ['RTOS'])

# ----------------------------------------------------------------------------
# C language-specific compiler flags
# 
env.Append(CFLAGS = [
    '-std=gnu11',
])

# ----------------------------------------------------------------------------
# C++ language-specific compiler flags
#
env.Append(CXXFLAGS = [
    '-std=gnu++14',
    '-fabi-version=0',
    '-fno-use-cxa-atexit',
    '-fno-threadsafe-statics',
])

# ----------------------------------------------------------------------------
#n General compilation flags
#
env.Append(CCFLAGS = [
    '-Og',
    '-fmessage-length=0',
    '-fsigned-char',
    '-ffunction-sections',
    '-fdata-sections',
    # '-ffreestanding',
    '-fno-move-loop-invariants',
    '-Wall',
    '-Wextra',
    '-std=c++17',
    '-g3',] + cortex_m4_flags)


# ----------------------------------------------------------------------------
# Linker flags
#
env.Append(LINKFLAGS = cortex_m4_flags + [
    '-Tldscripts/libs.ld',
    '-Tldscripts/mem.ld',
    '-Tldscripts/sections.ld',
    '-nostartfiles',
    '-Xlinker',
    '--gc-sections',
    '-u', '_printf_float',
    '-u', '_scanf_float',
    '-Wl,-Map,"%s.map"'%(vdir+proj_name),   # put map file in build directory
    '--specs=nano.specs',
    '--specs=rdimon.specs',                 # needed for semi-hosting
    ])


# ----------------------------------------------------------------------------
# Construct the source code directories and include
# paths for all sub-directories
#
sources  = []
includes = []

if GetOption('rtos'):
    SConscript(dirs = 'middleware', exports = ['env', 'sources', 'includes'])

SConscript(dirs = 'drivers', exports = ['env', 'sources', 'includes'])
SConscript(dirs = 'system',  exports = ['env', 'sources', 'includes'])



env['CPPPATH'] = includes

# ----------------------------------------------------------------------------
# Building the project is deferred to a SConscript file 
# in the /src folder.  This allows a script to build any / all
# projects automatically (for example, via a CI server)
# 
SConscript(dirs = 'src', variant_dir = vdir, exports = ['env', 'sources', 'proj_name', 'vdir'], duplicate=0)
