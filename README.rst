============
vmod_storage_name
============

**compatibility note: this vmod only targets Varnish version 4.1. Older versions were not tested, and newer versions can accomplish the same thing with pure VCL.**

----------------------
Varnish storage_name Module
----------------------

:Date: 02/28/2018
:Version: 1.0
:Manual section: 3

SYNOPSIS
========

import storage_name [from "path"] ;


DESCRIPTION
===========

Get the name and type of the current storage. This is only availble to be called
in the client side.

CONTENTS
========

STRING get()
------------

Prototype

  STRING get()

Description

  Get the name of the current storage. Any problems results with '""' being returned.

Example

  set req.http.storage_name = storage_name.get();

STRING type()
-------------

Prototype

  STRING type()

Description

  Get the type of the current storage. Any problems results with '""' being returned.

Example

  set req.http.storage_type = storage_name.type();


INSTALLATION
============

This will only compile with Varnish Cache Plus 4.1
