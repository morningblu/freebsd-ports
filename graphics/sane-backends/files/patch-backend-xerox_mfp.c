From 5ea227caeacd504b64eef301e83fa63e0a25b3f7 Mon Sep 17 00:00:00 2001
From: Alex Belkin <abc@telekom.ru>
Date: Tue, 8 Mar 2011 17:57:19 +0300
Subject: [PATCH] keep usb device by default (correct for bug introduced by tcp sub-backend

---
 backend/xerox_mfp.c |   27 +++++++++++----------------
 1 files changed, 11 insertions(+), 16 deletions(-)

diff --git a/backend/xerox_mfp.c b/backend/xerox_mfp.c
index e08b50f..d4672a7 100644
--- backend/xerox_mfp.c.orig
+++ backend/xerox_mfp.c
@@ -37,10 +37,10 @@
 static const SANE_Device **devlist = NULL;	/* sane_get_devices array */
 static struct device *devices_head = NULL;	/* sane_get_devices list */
 
-transport available_transports[] = {
+enum { TRANSPORT_USB, TRANSPORT_TCP, TRANSPORTS_MAX };
+transport available_transports[TRANSPORTS_MAX] = {
     { "usb", usb_dev_request, usb_dev_open, usb_dev_close, usb_configure_device },
     { "tcp", tcp_dev_request, tcp_dev_open, tcp_dev_close, tcp_configure_device },
-    { 0 }
 };
 
 static int resolv_state(int state)
@@ -824,7 +824,13 @@ free_devices (void)
   devices_head = NULL;
 }
 
-/* SANE API ignores return code of this callback */
+static transport *tr_from_devname(SANE_String_Const devname)
+{
+  if (strncmp("tcp", devname, 3) == 0)
+    return &available_transports[TRANSPORT_TCP];
+  return &available_transports[TRANSPORT_USB];
+}
+
 static SANE_Status
 list_one_device (SANE_String_Const devname)
 {
@@ -839,12 +845,7 @@ list_one_device (SANE_String_Const devname)
       return SANE_STATUS_GOOD;
   }
 
-  for (tr = available_transports; tr->ttype; tr++) {
-    if (!strncmp (devname, tr->ttype, strlen(tr->ttype)))
-      break;
-  }
-  if (!tr->ttype)
-    return SANE_STATUS_INVAL;
+  tr = tr_from_devname(devname);
 
   dev = calloc (1, sizeof (struct device));
   if (dev == NULL)
@@ -878,13 +879,7 @@ list_one_device (SANE_String_Const devname)
 static SANE_Status
 list_conf_devices (UNUSED (SANEI_Config * config), const char *devname)
 {
-    transport *tr;
-
-    for (tr = available_transports; tr->ttype; tr++) {
-	if (!strncmp (devname, tr->ttype, strlen(tr->ttype)))
-	    return tr->configure_device(devname, list_one_device);
-    }
-    return	SANE_STATUS_INVAL;
+  return tr_from_devname(devname)->configure_device(devname, list_one_device);
 }
 
 SANE_Status
-- 
1.7.2.5

