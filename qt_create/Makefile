# The following only works on ubuntu or similar linux operating systems.

RQP=roscreate-qt-pkg
RQP_PATH=$(shell rospack find qt_create)/scripts/$(RQP)

install:
	@echo "Creating link /usr/local/bin/$(RQP) -> $(RQP_PATH)"
	@sudo ln -sf $(PWD)/scripts/roscreate-qt-pkg /usr/local/bin

uninstall:
	@echo "Removing link /usr/local/bin/roscreate-qt-pkg"
	@sudo rm -f /usr/local/bin/roscreate-qt-pkg
