FROM ubuntu:latest

RUN apt-get update && apt-get install -y build-essential

WORKDIR /home/npal/Workspace2/ConcertTix/docker-app 

COPY inc/ ./inc/

COPY src/ ./src/

COPY Makefile .

RUN ls

RUN make all

CMD ["./build/booking_app"]

