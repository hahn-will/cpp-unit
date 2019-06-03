#!/bin/bash
cd ..
ls api/*.hpp -m | tr "\n" " " | sed "s/, /;/g" > build/headers
cd utils
