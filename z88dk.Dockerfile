# To create the image:
#   $ docker build -t z88dk -f z88dk.Dockerfile .
# To run the container:
#   $ docker run -v ${PWD}:/src/ -it z88dk <command>
FROM debian:bullseye

ENV Z88DK_PATH="/opt/z88dk" \
    SDCC_PATH="/tmp/sdcc"

RUN apt update && \
    apt -y dist-upgrade && \
    apt install -y g++ bison flex cmake ninja-build qbs ragel re2c dos2unix texinfo texi2html gdb curl cpanminus libboost-all-dev libmodern-perl-perl libyaml-perl liblocal-lib-perl libcapture-tiny-perl libpath-tiny-perl libtest-differences-perl libtext-table-perl libdata-hexdump-perl libregexp-common-perl libclone-perl vim vim-youcompleteme mc nano git

RUN git clone --depth 1 --recursive https://github.com/z88dk/z88dk.git ${Z88DK_PATH}

RUN cpanm App::Prove Capture::Tiny::Extended File::Path  CPU::Z80::Assembler Test::Cmd::Common Test::HexDifferences Object::Tiny::RW List::Uniq

RUN apt install -y libxml2-dev

RUN cd ${Z88DK_PATH} \
    && chmod 777 build.sh \
    && ./build.sh -l \
    && ./build.sh -b \
    && ./build.sh -b -l -e \
    && ./build.sh -b -l -t \
    && ./build.sh \
    && rm -fR ${SDCC_PATH}

ENV PATH="${Z88DK_PATH}/bin:${PATH}" \
    ZCCCFG="${Z88DK_PATH}/lib/config/"

ARG USER=build

RUN useradd -ms /bin/bash ${USER} && \
    passwd -d ${USER}

# Setup default user, when enter docker container
USER build

RUN vam install youcompleteme

WORKDIR /home/${USER}/src/
