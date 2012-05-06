
all:
	@echo "  build    : build the python package."
	@echo "  install  : install the python package into /usr/local."
	@echo "  distro   : build the distribution tarball."
	@echo "  register : register the package with PyPI."
	@echo "  upload   : upload the package to PyPI."
	@echo "  clean    : clean build/dist directories."

build:
	python setup.py build

install:
	sudo python setup.py install

distro:
	python setup.py sdist

register:
	python setup.py register

upload:
	python setup.py sdist upload

clean:
	rm -rf build dist MANIFEST

