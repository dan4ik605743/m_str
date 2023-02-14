FROM debian:experimental
LABEL maintainer="6057430gu@gmail.com"

RUN apt-get update -y --no-install-recommends && \
    apt-get install -y --no-install-recommends g++ make binutils cmake libboost-all-dev && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /usr/src/m_str
COPY . ./

RUN mkdir build && \
    cd build && \
    cmake .. && \
    make -j$(nproc) && \
    make install && \
    rm -rf /usr/src/m_str/*