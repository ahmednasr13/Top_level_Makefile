include make/preMakefile

PACKAGES:=libwelcome \
					main

export BUILD_DIR=$(shell pwd)/build

.PHONY: target
target: create_build_directory $(PACKAGES)

include make/postMakefile

.PHONY: clean
clean:
	@rm -rf $(BUILD_DIR)