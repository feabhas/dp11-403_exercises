docker run -i -v $(pwd):/usr/myapp feabhas/cpp11-scons:v1.0 scons
#docker run -i -v $(pwd):/usr/myapp feabhas/cpp11-scons:v1.0 ./myapp 
docker run -i -v $(pwd):/usr/myapp feabhas/cpp11-scons:v1.0 scons -c
