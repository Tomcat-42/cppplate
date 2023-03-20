FROM tomcat0x42/cppdev:latest AS builder

USER cppdev
WORKDIR /home/cppdev/app

COPY --chmod=0755 --chown=cppdev:cppdev . ./

# build deps
RUN xrepo install -y fmt cxxopts gtest benchmark tabulate
RUN xmake build -y

FROM ubuntu:23.04 AS runner

WORKDIR /app

# runtime deps
RUN apt-get update && apt-get install -y \
    libssl3 \
    mawk \
    && rm -rf /var/lib/apt/lists/*


COPY --from=builder \
    /home/cppdev/app/app \
    ./

ENTRYPOINT ["/app/app"]
