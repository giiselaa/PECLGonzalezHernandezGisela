.PHONY: clean All

All:
	@echo "----------Building project:[ PECLGonzalezHernandezGisela - Debug ]----------"
	@cd "PECLGonzalezHernandezGisela" && "$(MAKE)" -f  "PECLGonzalezHernandezGisela.mk"
clean:
	@echo "----------Cleaning project:[ PECLGonzalezHernandezGisela - Debug ]----------"
	@cd "PECLGonzalezHernandezGisela" && "$(MAKE)" -f  "PECLGonzalezHernandezGisela.mk" clean
