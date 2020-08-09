FROM centos

RUN yum update -y \
	&& yum upgrade -y

RUN yum install -y git nano vim emacs \
	&& dnf group install -y "Development Tools"

CMD ["/bin/bash"]
