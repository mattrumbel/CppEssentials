.PHONY: run build update push

run:
	docker run -it --rm mattrumbel/cpp_essentials:1.0

build:
	docker build -t mattrumbel/cpp_essentials:1.0 .

update:
	docker build -t mattrumbel/cpp_essentials:1.0 .

push:
	docker push mattrumbel/cpp_essentials:1.0
