============
vmod_storage_name
============

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

* :ref:`func_get`
* :ref:`func_type`

.. _func_get:

STRING get()
------------

Prototype
  STRING get()

Description
  Get the name of the current storage. Any problems results with '""' being returned.

Example
  set req.http.storage_name = storage_name.get();

.. _func_type:

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

This will only copmile with Varnish Cache Plus 4.1
