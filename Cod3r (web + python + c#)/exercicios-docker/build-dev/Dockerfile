FROM python:3.6
LABEL maintainer 'Aluno Cod3r <aluno@cod3r.com.br>'

RUN useradd www && \
    mkdir /app && \
    mkdir /log && \
    chown www /log

USER www
VOLUME /log
WORKDIR /app
EXPOSE 8000


ENTRYPOINT ["/usr/local/bin/python"]
CMD ["run.py"]

# RUM => sudo docker container run -it -v /home/sandesvitor/Study/code-lessons/"Cod3r (web + python + c#)"/exercicios-docker/build-dev/:/app -p 80:8000 --name python-server ex-build-dev