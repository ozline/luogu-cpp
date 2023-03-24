new:
ifdef id
ifneq ($(wildcard P$(id).cpp),)
	@echo "P$(id).cpp already exists";
else
	@cp template.cpp P$(id).cpp && code P$(id).cpp;
endif
else
	@echo "id is not defined"
endif