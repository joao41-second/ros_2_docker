#!/bin/bash

echo ¨ola user¨
set -e

source /opt/ros/foxy/setup.bash
exec "$@"
