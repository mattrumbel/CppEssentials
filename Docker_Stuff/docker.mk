.PHONY: run build update push

run:
	docker run -it --name cpp_container -v ~/cpp_container_host:/host_vol --rm mattrumbel/cpp_essentials:1.1

build:
	docker build -t mattrumbel/cpp_essentials:1.1 .

update:
	docker build -t mattrumbel/cpp_essentials:1.1 .

push:
	docker push mattrumbel/cpp_essentials:1.1
