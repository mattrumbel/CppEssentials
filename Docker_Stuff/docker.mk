IMAGE = mattrumbel/cpp_essentials
TAG = 1.1
CONTAINER_NAME = cpp_container


.PHONY: run build update push

run:
	docker run -it --name ${CONTAINER_NAME} -v ~/cpp_container_host:/host_vol --rm ${IMAGE}:${TAG}

build:
	docker build -t ${IMAGE}:${TAG} .

update:
	docker build -t ${IMAGE}:${TAG} .

push:
	docker push ${IMAGE}:${TAG}
