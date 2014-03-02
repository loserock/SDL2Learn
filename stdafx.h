/*
 * stdafx.h
 * 
 * Copyright 2014 loserock <loserock@gmail.com>
 * 
 */

#include <iostream>
#include <math.h>
#include <wchar.h>
#include <time.h>

#include <SDL.h>

#ifdef __WIN32__
    freopen("CON", "w", stdout);
    freopen("CON", "w", stderr);
#endif


#ifndef __ERROR_HANDLING__
#define __ERROR_HANDLING__

typedef enum 
{
	ErrorType_Caught_SDL_Error,		// throwned handled error from SDL error detect
	ErrorType_Unknown_Error			// unknown error
} ErrorType;

#define CHECKSDLERROR													\
	fprintf(stderr, " -> Error was in %s:%dL in function %s at"			\
					" (h:m:s)!\n",										\
					SDL_FILE, SDL_LINE, SDL_FUNCTION);					\
	const char* errorMsg = SDL_GetError();								\
	if (strlen(errorMsg) > 0)											\
	{																	\
		fprintf(stderr, " ---> SDL Error Message: %s\n", errorMsg);		\
		throw ErrorType_Caught_SDL_Error;								\
	} else throw ErrorType_Unknown_Error;

inline void _chkError(int E) {if (E < 0) { CHECKSDLERROR } };
inline void _chkError(void* E) {if (!E) { CHECKSDLERROR } };

#define CHECKSDLRETURNERROR(E) _chkError(E);

/*
		int dbgNr(0);													\
		SDL_assert( false );											\
		const SDL_assert_data* errorData = SDL_GetAssertionReport();	\
		while (errorData)												\
		{																\
			dbgNr++;													\
			fprintf(stderr, " -> Error was in %s:%dL in function %s at"	\
				" (h:m:s), triggered %d times!\n",						\
				errorData->filename, errorData->linenum,				\
				errorData->function, errorData->trigger_count);			\
			errorData = errorData->next;								\
		}																\
		if (dbgNr > 0) throw ErrorType_Caught_SDL_Error;				\
 */

#endif	//__ERROR_HANDLING__
