#!/bin/sh
#
# $Id$
#
# Maintenance shell script to vacuum and backup database
# Put this in /usr/local/etc/periodic/daily, and it will be run 
# every night
#
# Written by Palle Girgensohn <girgen@partitur.se>
#
# In public domain, do what you like with it,
# and use it at your own risk... :)
#
############################

# arguments to pg_dump
PGDUMP_ARGS="-b -F c"

# the directory where the backups will reside
# ${HOME} is pgsql's home directory
PGBACKUPDIR=${HOME}/backups

# some data is amazingly more compressed with bzip2, esp. blobs, it seems
# if your're short on diskspace, give it a try and set USEBZIP=yes
USEBZIP=no

############################

DIR=`dirname $0`
progname=`basename $0`
PRG=`cd $DIR; pwd `/$progname

# Run as user pgsql
if [ `id -un` != pgsql ]; then
    su -l pgsql -c ${PRG}
    exit $?
fi

if [ X${USEBZIP} = Xyes ]; then
    BZIP=`which bzip2 || echo true`
else
    BZIP=true
fi

# PGBACKUPDIR must be writeable by user pgsql
# ~pgsql is just that under normal circumstances,
# but this might not be where you want the backups...
if [ ! -d ${PGBACKUPDIR} ] ; then 
    echo Creating ${PGBACKUPDIR}
    mkdir ${PGBACKUPDIR}
    chmod 700 ${PGBACKUPDIR}
fi

echo
echo "PostgreSQL maintenance"

# Protect the data
umask 077
dbnames=`psql -q -t -A -d template1 -c "SELECT datname FROM pg_database WHERE datname != 'template0'"`
rc=$?
for db in ${dbnames}; do
    echo -n " $db"
    file=${PGBACKUPDIR}/pgdump_${db}_`date "+%Y%m%d"`
    pg_dump ${PGDUMP_ARGS} -d $db -f ${file}
    [ $? -gt 0 ] && rc=3
    ${BZIP} ${file}
done

if [ $rc -gt 0 ]; then
    echo
    echo "Errors were reported during backup."
fi

echo
echo "vacuuming..."
vacuumdb -a -z -q
if [ $? -gt 0 ]
then
    echo
    echo "Errors were reported vacuum."
    rc=3
fi

# cleaning up old data
find ${PGBACKUPDIR} \( -name 'pgdump_*'.${GZIPEXT} -o -name 'pgdumpall_*'.${GZIPEXT} \) \
		    -a -atime +7 -delete

exit $rc
