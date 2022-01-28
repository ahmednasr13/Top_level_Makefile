#pragma once

#define EXPORT __attribute__((visibility("default")))

EXPORT void welcome(void);
EXPORT int welcome(char *name);