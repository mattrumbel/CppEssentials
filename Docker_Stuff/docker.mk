.PHONY: run build update push

run:
	docker run -it --rm mattrumbel/cpp_essentials:1.1

build:
	docker build -t mattrumbel/cpp_essentials:1.1 .

update:
	docker build -t mattrumbel/cpp_essentials:1.1 .

push:
	docker push mattrumbel/cpp_essentials:1.1
