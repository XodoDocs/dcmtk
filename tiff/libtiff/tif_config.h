
// Notes for: WinCE/WinMobile License.
// Ivan: Defines used for a previous build on Win Mobile 5.
// #define HAVE_FCNTL_H 1
// #define HAVE_SYS_TYPES_H 1
// #define HAVE_SEARCH_H 1
// Also see the new header "tiffconf.wince.h"
// Also consult with the last tiff version that worked with WinCE (rev 1145).

#ifdef WINCE
 #include<tif_config.wince.h>
#else
 /* Define to 1 if you have the <assert.h> header file. */
 #define HAVE_ASSERT_H 1

 /* Define to 1 if you have the <fcntl.h> header file. */
 #define HAVE_FCNTL_H 1

 /* Define as 0 or 1 according to the floating point format supported by the machine */
 #define HAVE_IEEEFP 1

 /* Define to 1 if you have the `jbg_newlen' function. */
 #define HAVE_JBG_NEWLEN 1

 /* Define to 1 if you have the <string.h> header file. */
 #define HAVE_STRING_H 1

 /* Define to 1 if you have the <sys/types.h> header file. */
 #define HAVE_SYS_TYPES_H 1

 /* Define to 1 if you have the <io.h> header file. */
 /* #define HAVE_IO_H 1 */

 /* Define to 1 if you have the <search.h> header file. */
 /* #define HAVE_SEARCH_H 1 */

 /* Define to 1 if you have the `setmode' function. */
 #define HAVE_SETMODE 1

 /* The size of a `int', as computed by sizeof. */
 #define SIZEOF_INT 4

 /* The size of a `long', as computed by sizeof. */
 #define SIZEOF_LONG 4

 /* Signed 64-bit type formatter */
 #define TIFF_INT64_FORMAT "%I64d"

 /* Signed 64-bit type */
 #define TIFF_INT64_T signed __int64

 /* Unsigned 64-bit type formatter */
 #define TIFF_UINT64_FORMAT "%I64u"

 /* Unsigned 64-bit type */
 #define TIFF_UINT64_T unsigned __int64

 /* Set the native cpu bit order */
 #define HOST_FILLORDER FILLORDER_LSB2MSB

#if _MSC_VER < 1900
 #define snprintf _snprintf
#endif

 /* Define to 1 if your processor stores words with the most significant byte
 first (like Motorola and SPARC, unlike Intel and VAX). */
 #ifdef __BIG_ENDIAN__   /* On Mac Power PC */
	 #define WORDS_BIGENDIAN 1
	 #define HAVE_UNISTD_H 1   /* to go around the problem on Mac PowerPC when creating multipage TIFF in PDF2Image */
#elif defined(EMSCRIPTEN) || defined(__APPLE__) 
	 #define HAVE_UNISTD_H 1 
#endif

 /* Define to `__inline__' or `__inline' if that's what the C compiler calls it, or to nothing if 'inline' is not supported under any name.  */
 #ifndef __cplusplus
	 #ifndef inline
		 # define inline __inline
	 #endif
 #endif

 #ifdef _WIN32
	 #define lfind _lfind   // On Windows
 #else 
	 #undef  HAVE_LFIND
 #endif
#endif

