FROM gcc:12.2.0

RUN apt-get update && apt-get install -y \
    make \
    lcov \
    check \
    libsubunit-dev \
    valgrind \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN echo 'FLAG = -lcheck -lm -lsubunit -lpthread -lrt' >> Makefile_temp && \
    grep -v "FLAG =" Makefile >> Makefile_temp && \
    mv Makefile_temp Makefile

RUN mkdir -p tpr_decimal/arifmetic tpr_decimal/comparison tpr_decimal/convertor \
    tpr_decimal/help tpr_decimal/other tpr_test

RUN chmod +x /app/Makefile

CMD ["make", "all", "test", "testVerter", "clean", "rebuild", "gcov_report"]