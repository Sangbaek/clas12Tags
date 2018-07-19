#!/bin/csh

setenv JLAB_ROOT /jlab
setenv JLAB_VERSION 2.2
setenv CLAS12TAG 4a.2.4

setenv GEMC /jlab/clas12Tags/$CLAS12TAG/source
setenv GEMC_VERSION $CLAS12TAG

source $JLAB_ROOT/$JLAB_VERSION/ce/jlab.csh keepmine
setenv GEMC_DATA_DIR /jlab/clas12Tags/$CLAS12TAG

setenv CLAS12_LIB $JLAB_SOFTWARE/clas12/lib
setenv CLAS12_INC $JLAB_SOFTWARE/clas12/inc
setenv CLAS12_BIN $JLAB_SOFTWARE/clas12/bin

setenv PATH ${PATH}:${CLAS12_BIN}

set autolist
alias l ls -l
alias lt ls -lt

