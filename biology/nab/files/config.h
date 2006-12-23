#  NAB configuration file, created with: ./configure -p4 -static gcc

###############################################################################

# (1)  You need to define the symbol NABHOME in your environment

#    NABHOME should be an absolute path to the top-level NAB directory;
#    files are installed to the following directories:

BINDIR=$(NABHOME)/bin
LIBDIR=$(NABHOME)/lib
INCDIR=$(NABHOME)/include

###############################################################################


#  (2) If you want to search additional libraries by default, add them
#      to the FLIBS variable here.  (External libraries can also be linked into
#      NAB programs simply by including them on the command line; libraries
#      included in FLIBS are always searched.)

FLIBS= $(LIBDIR)/libsym.a $(LIBDIR)/lapack.a $(LIBDIR)/blas.a $(LIBDIR)/f2c.a -static   

###############################################################################

#  (3)  Modify any of the following if you need to change, e.g. to use gcc
#        rather than cc, etc.

SHELL=/bin/sh

#  Set the C compiler, etc. 

#          For GNU:  CC-->gcc; LEX-->flex; YACC-->bison -y -t;
#          Note: If your lexer is "really" flex, you need to set
#          LEX=flex below.  For example, on many linux distributions,
#          /usr/bin/lex is really just a pointer to /usr/bin/flex,
#          so LEX=flex is necessary.  In general, gcc seems to need
#          flex.

NABFLAGS=

LEX=    flex
YACC=   yacc
AR=     ar
RANLIB= ranlib

#  Set the C-preprocessor.  Code for a small preprocessor is in
#    uccp-1.3;  it gets installed as $(NABHOME)/bin/ucpp;
#    this can generally be used (maybe not on 64-bit machines like altix).

CPP=    /usr/local/bin/ucpp -l

#  If you are going to link in Fortran routines, you need
#  to set the compiler information here.  (Also, add the appropriate entries
#  to the FLIBS variable, above.)
#
#FC=f77
#FFLAGS?=$(FFLAGS)
#FOPTFLAGS?=$(FFLAGS)
FREEFORMAT_FLAG=-ffree-form

#  These variables control whether we will use compiled versions of BLAS
#  and LAPACK (which are generally slower), or whether those libraries are
#  already available (presumably in an optimized form).

LAPACK=install
BLAS=install
F2C=install
UCPP=

#  For Windows/cygwin, set SFX to ".exe"; for Unix/Linux leave it empty:

SFX=

