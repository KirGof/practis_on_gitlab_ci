#!/usr/bin/bash

TELEGRAM_API_TOKEN=`cat "$CI_PROJECT_DIR/src/part_6/token.txt"`
TEXT=`cat $CI_PROJECT_DIR/res.txt`
METHOD_NAME=sendMessage
CHAT_ID="360699768"
URL="https://api.telegram.org/bot$TELEGRAM_API_TOKEN/$METHOD_NAME"

curl -s $URL -d "chat_id=$CHAT_ID&text=$TEXT"
