FROM debian:experimental
MAINTAINER Danil Danevich <6057430gu@gmail.com>

RUN apt-get -qq update && \
    apt-get -qq install -y g++ make binutils cmake libboost-all-dev

WORKDIR /usr/src/m_str
COPY m_str m_str
COPY CMakeLists.txt ./

RUN cmake . && \
    make -j$(nproc) && \
    make install && \
    rm -rf /usr/src/tgbot-cpp/*