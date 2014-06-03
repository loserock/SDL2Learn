/*
 * main.cpp
 * 
 * Copyright 2014 loserock <loserock@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#include "main.h"

int main(int argc, char **argv)
{
	printf("SDL2 test\n");
	int nCPU = SDL_GetCPUCount();
	printf("Number of CPUs: %d\n", nCPU); //DEBUG
	
	try
	{
		int e = SDL_Init(SDL_INIT_VIDEO);
		CHECKSDLRETURNERROR(e)
		
		SDL_Window *window;
		window = SDL_CreateWindow(
				"SDL2 test window",                  // window title
				SDL_WINDOWPOS_UNDEFINED,           // initial x position
				SDL_WINDOWPOS_UNDEFINED,           // initial y position
				640,                               // width, in pixels
				480,                               // height, in pixels
				SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS                  // flags - see below
			);
		CHECKSDLRETURNERROR(window)
		
		SDL_Delay(5000);
		SDL_DestroyWindow(window);
	}
	catch (ErrorType exc)
	{
		const char* timeStr = "hh:mm:ss";
		if (exc == ErrorType_Caught_SDL_Error)
		{
			fprintf(stderr, "Program terminated at (%s)!\n", timeStr); //TODO
		}
		else if (exc == ErrorType_Unknown_Error)
		{
			fprintf(stderr, "Unspecified SDL error! Program terminated at (%s)!\n", timeStr); //TODO
		}
	}
	catch (...)
	{
		fprintf(stderr, "Unspecified exception at (h:m:s), program terminated!\n");
	}
	
	SDL_Quit();
	
	return 0;
}


