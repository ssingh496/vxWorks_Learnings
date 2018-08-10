
 /* @file		vxWorksDriverDemo.c
 * @brief       vxWorks Demo Device Driver
 * @author		Sandeep Pratap Singh
 * @date		10 Aug 2018
 */

 
 /* includes */
#include <vxWorks.h>
#include <ioLib.h>
#include <iosLib.h>
#include <errnoLib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <vxWorksDriverDemo.h>

#define MAX_SIZE 100


/* Struct for the driver*/
typedef struct	
{
  DEV_HDR devHdr; /* DEV_HDR - device header for all device structures */
  int mode;
  int nb;
  char data[MAX_SIZE];
} demo_dev;

/*variable to store the major number*/
int demoDrvMajor=-1;	

/* functions to register with driver*/
int demoOpen();
int demoRead();
int demoWrite();
int demoClose();
STATUS demoIoctl();


/*function for installing a demo driver */
STATUS demoDrv ()
{
  if (demoDrvMajor > 0)
    return (OK);

  /*install a kernel I/O driver and allocate the majaor number dynamically*/
  demoDrvMajor = iosDrvInstall (demoOpen, (FUNCPTR)NULL, demoOpen,
				demoClose, demoRead, demoWrite, demoIoctl);

  return (demoDrvMajor == ERROR ? ERROR : OK);
}



/* Demo Driver Create*/
STATUS demoDevCreate (char* name)
{
  STATUS status;
  demo_dev *pDev;

  if (demoDrvMajor < 0)
    {
      errnoSet (S_ioLib_NO_DRIVER);
      return (ERROR);
    }

  if ((pDev = (demo_dev *) malloc (sizeof (demo_dev))) == NULL)
    return (ERROR);
 
  pDev->nb=0;
  strcpy(pDev->data,"");

  status = iosDevAdd ((DEV_HDR *) pDev, name, demoDrvMajor);

  return (status);
}


/*Open Function*/
int demoOpen (demo_dev* pDev, char* name, int mode)
{
  printf("Open %s device\n",name);
  pDev->mode=mode;
  pDev->nb++;

  return ((int) pDev);
}

/*Close Function*/
int demoClose (demo_dev* pDev)
{
  printf("Close sur device\n");
  pDev->nb--;

  return (OK);
}

/*Read Function*/
int demoRead (demo_dev* pDev, char* buffer, int maxbytes)
{
  printf("Read sur device\n");
  strncpy(buffer,pDev->data,maxbytes);

  return (strlen(buffer)+1);
}

/*Write Function*/
int demoWrite (demo_dev* pDev, char* buffer, int maxbytes)
{
  printf("Write sur device\n");
  strncpy(pDev->data,buffer,maxbytes);

  return (strlen(pDev->data)+1);
}

/*IOCTL Function*/
int demoIoctl (demo_dev* pDev, int function, int arg)
{   
  int status = OK;
  
  (void)arg;
  printf("Ioctl sur device\n");

  switch (function)
    {
    case GET_OPEN:
      status = pDev->nb;
      break;

    case GET_MODE:
      status = pDev->mode;
      break;

    default:
      status = ERROR;
      break;
    }

  return (status);
}



