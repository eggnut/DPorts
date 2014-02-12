
$FreeBSD: head/multimedia/mxflib/files/patch-mxflib_smartptr.h 340035 2014-01-17 13:31:29Z olgeni $

--- mxflib/smartptr.h.orig
+++ mxflib/smartptr.h
@@ -503,7 +503,7 @@
 		}
 
 		//! Comparison function to allow sorting by indexed value
-		bool operator<(SmartPtr &Other) { return this.operator<(*Other->GetPtr()); }
+		bool operator<(SmartPtr &Other) { return this->operator<(*Other->GetPtr()); }
 
 		//! Get a cast version of the pointer
 		/*! This is used via the SmartPtr_Cast() Macro to allow MSVC 6 to work!!
