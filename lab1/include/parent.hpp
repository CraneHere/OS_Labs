#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

#define PIPE_READ 0
#define PIPE_WRITE 1

void ParentRoutine(const char *pathToChild, std::istream &in);
