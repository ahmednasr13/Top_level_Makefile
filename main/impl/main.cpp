#include <stdio.h>
#include <dlfcn.h>

static int reportError() {
  char *err = dlerror();
  if(err) {
    printf("Error: %s\n", err);
    return 1;
  }
  return 0;
}

int main(int argc, char **argv) {
  char *err;
  void *lib_handler = dlopen("libwelcome.so", RTLD_LAZY | RTLD_LOCAL);
  if(reportError())
    return 1;

  void (*welcome_void_ptr)(void) = (void (*)(void))dlsym(lib_handler, "_Z7welcomev");
  if(reportError())
    return 1;
  
  int (*welcome_pc_ptr)(char *) = (int (*)(char *))dlsym(lib_handler, "_Z7welcomePc");
  if(reportError())
    return 1;

  (*welcome_void_ptr)();

  char my_name[1024];
  printf("Enter your name: ");
  scanf("%s", my_name);
  (*welcome_pc_ptr)(my_name);

  dlclose(lib_handler);
  if(reportError())
    return 1;

  return 0;
}