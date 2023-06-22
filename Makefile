DIR = $(shell pwd)
FILE = $(DIR)/P$(id).cpp

.PHONY: new
new:
ifdef id
ifneq ($(wildcard P$(id).cpp),)
	@echo "P$(id).cpp already exists";
else
	@touch $(FILE)
	@echo "/**" >> $(FILE)
	@echo " * @file P$(id).cpp" >> $(FILE)
	@echo " * @author ozlinex" >> $(FILE)
	@echo " * @brief " >> $(FILE)
	@echo " * @date $(shell date +%Y-%m-%d)" >> $(FILE)
	@echo " */" >> $(FILE)
	@echo "" >> $(FILE)
	@cat ./template/template.cpp >> $(FILE)
	@code $(FILE)
endif
else
	@echo "id is not defined"
endif