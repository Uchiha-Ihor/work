FROM gcc:latest

COPY . /usr/src/cpp_docker_test

WORKDIR /usr/src/cpp_docker_test

RUN g++ -o TestDockC C_with_Docker.cpp

CMD [ "./TestDockC" ]