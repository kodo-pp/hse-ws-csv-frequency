project('csv-frequency', 'cpp', default_options: ['cpp_std=c++17'])

sources = [
    'src/arguments.cpp',
    'src/frequency_analyzer.cpp',
    'src/io.cpp',
    'src/main.cpp',
    'src/util/split.cpp',
    'src/util/string_to_int.cpp',
]

includes = include_directories(
    'include',
)

executable('csv-frequency', sources, include_directories: includes)
