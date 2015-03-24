#!/bin/sh

BASEDIR=$(dirname $0)
LOGDIR=log
LIBDIR=lib
CMD=KSMD

cd $BASEDIR
echo "Go into $PWD"

#libs
if [[ ! -d "$LIBDIR" ]]; then
  echo "Libs dir is missing"
  exit 1
fi
export LD_LIBRARY_PATH="$BASEDIR/$LIBDIR"

#logs
if [ -e "$LOGDIR" ]; then
  if [[ ! -d "$LOGDIR" ]]; then
    echo "Fail to mkdir $PWD/$LOGDIR"
    exit 1
  fi
else
  mkdir $LOGDIR
  echo "Mkdir $PWD/$LOGDIR"
fi

#exec
if [[ ! -x "$CMD" ]]; then
  echo "Require exec privilege for $CMD"
  exit 1
else
  eval ./$CMD $@ &
  exit 0
fi

