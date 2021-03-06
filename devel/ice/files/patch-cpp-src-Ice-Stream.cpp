--- cpp.orig/src/Ice/Stream.cpp	2011-06-15 21:43:59.000000000 +0200
+++ cpp/src/Ice/Stream.cpp	2012-03-04 20:14:53.000000000 +0100
@@ -8,10 +8,19 @@
 // **********************************************************************
 
 #include <Ice/Stream.h>
+#include <Ice/LocalException.h>
 
 using namespace std;
 using namespace Ice;
 using namespace IceInternal;
 
-IceUtil::Shared* IceInternal::upCast(InputStream* p) { return p; }
-IceUtil::Shared* IceInternal::upCast(OutputStream* p) { return p; }
+IceUtil::Shared* Ice::upCast(InputStream* p) { return p; }
+IceUtil::Shared* Ice::upCast(OutputStream* p) { return p; }
+
+namespace IceInternal
+{
+  void delegateThrowMarshalException(const char* file, int line , const ::std::string& message)
+  {
+    throw Ice::MarshalException(file, line, message);
+  }
+}
