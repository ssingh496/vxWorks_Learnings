/* ctors and dtors arrays -- to be used by runtime system */
/*   to call static constructors and destructors          */
/*                                                        */
/* NOTE: Use a C compiler to compile this file. If you    */
/*       are using GNU C++, be sure to use compile this   */
/*       file using a GNU compiler with the               */
/*       -fdollars-in-identifiers flag.                   */

#if defined(_HAVE_TOOL_XTORS)
#include <vxWorks.h>
#include TOOL_HEADER (toolXtors.h)
#else
char __dso_handle = 0;

extern void (*_ctors[])();
void (*_ctors[])() =
    {
    0
    };

extern void (*_dtors[])();
void (*_dtors[])() =
    {
    0
    };
#endif /* _HAVE_TOOL_XTORS */

/* build variables */
#ifdef __GNUC__
__asm("	.section \".wrs_build_vars\",\"a\"");
#endif
#ifdef __DCC__
__asm("	.section \".wrs_build_vars\",\"r\"");
#endif
__asm(" .ascii \"tag SMP 1\"");
__asm(" .byte 0");
__asm("	.ascii \"end\"");
__asm("	.byte 0");
__asm("	.previous");
