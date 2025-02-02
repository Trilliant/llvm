llvm-objdump - LLVM's object file dumper
========================================

.. program:: llvm-objdump

SYNOPSIS
--------

:program:`llvm-objdump` [*commands*] [*options*] [*filenames...*]

DESCRIPTION
-----------
The :program:`llvm-objdump` utility prints the contents of object files and
final linked images named on the command line. If no file name is specified,
:program:`llvm-objdump` will attempt to read from *a.out*. If *-* is used as a
file name, :program:`llvm-objdump` will process a file on its standard input
stream.

COMMANDS
--------
At least one of the following commands are required, and some commands can be
combined with other commands:

.. option:: -a, --archive-headers

  Display the information contained within an archive's headers.

.. option:: -d, --disassemble

  Display assembler mnemonics for the machine instructions. Disassembles all
  text sections found in the input file(s) by default.

.. option:: -D, --disassemble-all

  Display assembler mnemonics for the machine instructions. Disassembles all
  sections found in the input file(s) by default.
  
.. option:: --disassemble-functions=<func1[,func2,...]>

  Disassemble only the specified symbols. Implies :option:`--disassemble`.

.. option:: --dwarf=<value>

  Dump the specified DWARF debug sections. The supported values are:

  `frames` - .debug_frame

.. option:: -f, --file-headers

  Display the contents of the overall file header.

.. option:: --fault-map-section

  Display the content of the fault map section.

.. option:: -h, --headers, --section-headers

  Display summaries of the headers for each section.

.. option:: --help

  Display usage information and exit. Does not stack with other commands.

.. option:: -p, --private-headers

  Display format-specific file headers.

.. option:: -r, --reloc

  Display the relocation entries in the file.

.. option:: -R, --dynamic-reloc

  Display the dynamic relocation entries in the file.

.. option:: --raw-clang-ast

  Dump the raw binary contents of the clang AST section.

.. option:: -s, --full-contents

  Display the contents of each section.

.. option:: -t, --syms

  Display the symbol table.

.. option:: -u, --unwind-info

  Display the unwind info of the input(s).

.. option:: --version

  Display the version of this program. Does not stack with other commands.

.. option:: -x, --all-headers

  Display all available header information. Equivalent to specifying
  :option:`--archive-headers`, :option:`--file-headers`,
  :option:`--private-headers`, :option:`--reloc`, :option:`--section-headers`,
  and :option:`--syms`.

OPTIONS
-------
:program:`llvm-objdump` supports the following options:

.. option:: --adjust-vma=<offset>

  Increase the displayed address in disassembly or section header printing by
  the specified offset.

.. option:: --arch-name=<string>

  Specify the target architecture when disassembling. Use :option:``--version``
  for a list of available targets.

.. option:: -C, --demangle

  Demangle symbol names in the output.

.. option:: -j, --section=<section1[,section2,...]>

  Perform the specified command(s) on the specified section(s) only. For Mach-O
  use `segment,section` to specify the section name.

.. option:: -l, --line-numbers

  When disassembling, display source line numbers with disassembly. Implies
  :option:`--disassemble`.

.. option:: -M, --disassembler-options=<opt1[,opt2,...]>

  Pass target-specific disassembler options. Currently supported for ARM targets
  only. Available options are ``reg-names-std`` and ``reg-names-raw``.

.. option:: --mcpu=<cpu-name>

  Target a specific CPU type for disassembly. Specify ``--mcpu=help`` to display
  available CPUs.

.. option:: --mattr=<a1,+a2,-a3,...>

  Enable/disable target-specific attributes. Specify ``--mcpu=help`` to display
  the available attributes.

.. option:: --no-leading-addr

  When disassembling, do not print the leading address in the disassembly
  output.

.. option:: --no-show-raw-insn

  When disassembling instructions, do not print the raw bytes of the
  instruction.

.. option:: --print-imm-hex

  Use hex format when printing immediate values in disassembly output.

.. option:: -S, --source

  When disassembling, display source inlined with the disassembly.
  Implies :option:`--disassemble`.

.. option:: --show-lma

  Display the LMA column when dumping ELF section headers. Defaults to off
  unless any section has different VMA and LMAs.

.. option:: --start-address=<address>

  When disassembling, only disassemble from the specified address.

  When printing relocations, only print the relocations patching offsets from at least ``address``.

  When printing symbols, only print symbols with a value of at least ``address``.

.. option:: --stop-address=<address>

  When disassembling, only disassemble up to, but not including the specified address.

  When printing relocations, only print the relocations patching offsets up to ``address``.

  When printing symbols, only print symbols with a value up to ``address``.

.. option:: --triple=<string>

  Target triple to disassemble for, see ``--version`` for available targets.

.. option:: -w, --wide

  Ignored for compatibility with GNU objdump.

.. option:: --x86-asm-syntax=<style>

  When used with the ``--disassemble`` option, choose style of code to emit from
  X86 backend. Supported values are:

   .. option:: att

    AT&T-style assembly

   .. option:: intel

    Intel-style assembly


  The default disassembly style is **att**.

.. option:: -z, --disassemble-zeroes

  Do not skip blocks of zeroes when disassembling.

.. option:: @<FILE>

  Read command-line options and commands from response file `<FILE>`.

MACH-O ONLY OPTIONS AND COMMANDS
--------------------------------

.. option:: --arch=<architecture>

  Specify the architecture to disassemble. see ``--version`` for available
  architectures.

.. option:: --archive-member-offsets

  Print the offset to each archive member for Mach-O archives (requires
  :option:`--archive-headers`).

.. option:: --bind

  Display binding info

.. option:: --cfg

  Create a CFG for every symbol in the object file and write it to a graphviz
  file.

.. option:: --data-in-code

  Display the data in code table.

.. option:: --dis-symname=<name>

  Disassemble just the specified symbol's instructions.

.. option:: --dylibs-used

  Display the shared libraries used for linked files.

.. option:: --dsym=<string>

  Use .dSYM file for debug info.

.. option:: --dylib-id

  Display the shared library's ID for dylib files.

.. option:: --exports-trie

  Display exported symbols.

.. option:: -g

  Print line information from debug info if available.

.. option:: --full-leading-addr

  Print the full leading address when disassembling.

.. option:: --indirect-symbols

  Display the indirect symbol table.

.. option:: --info-plist

  Display the info plist section as strings.

.. option:: --lazy-bind

  Display lazy binding info.

.. option:: --link-opt-hints

  Display the linker optimization hints.

.. option:: -m, --macho

  Use Mach-O specific object file parser. Commands and other options may behave
  differently when used with ``--macho``.

.. option:: --no-leading-headers

  Do not print any leading headers.

.. option:: --no-symbolic-operands

  Do not print symbolic operands when disassembling.

.. option:: --non-verbose

  Display the information for Mach-O objects in non-verbose or numeric form.

.. option:: --objc-meta-data

  Display the Objective-C runtime meta data.

.. option:: --private-header

  Display only the first format specific file header.

.. option:: --rebase

  Display rebasing information.

.. option:: --universal-headers

  Display universal headers.

.. option:: --weak-bind

  Display weak binding information.

BUGS
----

To report bugs, please visit <http://llvm.org/bugs/>.

SEE ALSO
--------

:manpage:`llvm-nm(1)`, :manpage:`llvm-readelf(1)`, :manpage:`llvm-readobj(1)`
