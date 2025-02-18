FROM ubuntu:24.04 AS ubuntu2404_common_deps
ENV DEBIAN_FRONTEND=noninteractive
RUN apt update && \
    apt install -y \
    git \
    python3 \
    build-essential \
    xz-utils \
    wget

RUN wget -O - https://raw.githubusercontent.com/alec-chicherini/development-scripts/refs/heads/main/cmake/install_cmake.sh 2>/dev/null | bash

FROM ubuntu2404_common_deps AS site_repotest_ru_build
ENV DEBIAN_FRONTEND=noninteractive

RUN apt update && \
    apt install -y \
    clang

COPY . /site-repotest-ru

RUN cd /site-repotest-ru && mkdir build && cd build && \
    git submodule init && git submodule update && \
    cmake .. && \
    cmake --build . && \
    mkdir /result && \
    /site-repotest-ru/build/site-repotest-ru > /result/index.html

RUN chmod 755 /site-repotest-ru/scripts/run_python_http_server.sh
ENTRYPOINT ["/site-repotest-ru/scripts/run_python_http_server.sh", "/result"]