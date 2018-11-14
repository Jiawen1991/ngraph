.. embedding_lookup.rst:

###############
EmbeddingLookup
###############

.. code-block:: cpp

   EmbeddingLookup  // Convert sequences of indices into sequences of vectors


Description
===========

EmbeddingLookup operation.

Inputs
------

+-----------------+-------------------------+--------------------------------+
| Name            | Element Type            | Shape                          |
+=================+=========================+================================+
| ``data``        | any                     | :math:`(\ldots, T)`            |
+-----------------+-------------------------+--------------------------------+
| ``weights``     | any                     | :math:`(V,W)`                  |
+-----------------+-------------------------+--------------------------------+

Outputs
-------

+-----------------+-------------------------+--------------------------------+
| Name            | Element Type            | Shape                          |
+=================+=========================+================================+
| ``output``      | same as ``data``        | :math:`(\ldots, T, W)`         |
+-----------------+-------------------------+--------------------------------+


Mathematical Definition
=======================

.. math::

   \mathtt{output}\left[\ldots, t, w\right] = \mathtt{weights}\left[\mathtt{data}\left[\ldots, t\right], w\right]

Backprop
========

C++ Interface
=============

.. doxygenclass:: ngraph::op::EmbeddingLookup
   :project: ngraph
   :members:
