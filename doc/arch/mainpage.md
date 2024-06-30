Architecture Description of the cc_rpc framework
================

[TOC] 

**Usage Note**

© We acknowledge that this document uses material from the arc 42
architecture template, <http://www.arc42.de>. Created by Dr. Peter
Hruschka & Dr. Gernot Starke.

Introduction and Goals
======================

The cc_rpc framework shall provide an easily usable software framework for 
remote procedure calls needed in the distributed systems of the company.

Remote Procedure calls are interfaces between components which could be easily 
described by request response mechanisms.

It bundles the commonly used components of remote procedure calls and allows 
their reuse together with domain specific (software) interfaces.

Architects of domain specific components of the software and Application developers shall be able to define 
simple functional interfaces required or provided by their component. 

In addition they should be enabled to discuss them with the architects and the developers 
of the serving component without the need to discuss the details of the transporting mechanism. 

On the other side the base software for transporting these calls between can be developed in 
a few shareable components which can be reused by all domain specific components.
For the transport of the RPC Messages standard components for this transport mechanism can be used.

For the implementation of a domain specific interface always a so called stub is needed which takes 
over the encoding and decoding of the method names, call parameters and return values to their respective messages 
RPC.

The generation of these stubs shall be automated as far as possible by generating them from the call interface.

The implementation of the framework  will try to make use of modern C++ templates and template functions 
with variadic arguments and constexpr to make this possible without using 
an intermediate Interface Definition Language.

Requirements Overview
---------------------

**The framework shall provide easy remote function calls.**

The application developer shall be able to use a simple functional interface for defining and using the RPC methods.

The RPC client stub functionality shall be completely hidden for the application developer.

The RPC server stub functionality shall be completely hidden for the server (or service) developer.

The RPC framework developer may use code generators or template functions to automate the encoding 
and decoding of RPC messages. 

**The Transport Protocol shall be HTTP. (this is not yet finalized)**

The application developer shall be able to use a string to define the transport and address of the RPC server.

The application interface of the RPC framework shall use strings 
as service and method names for the service interface methods. 

**For the remote functions only primitive parameter and return types are required.**

The RPC framework shall support primitive types for parameters.

The RPC framework shall support primitive types for returned data.

Quality Goals 
-------------

| Name                              | Description                               | Priority |
| --------------------------------- | ----------------------------------------- |--------- |
| clear  architecture               | clear structure                           |    1     |
| simple  architecture              | simple to understand and to implement     |    2     |
| effective architecture            | effective change of architecture possible |    3     |

Stakeholders
------------


| Role/Name                 | Contact     | Expectations  |
|---------------------------|-------------|---------------|
| System Architect          | Contact-TBD | *&lt;TBD*&gt; |
| Application Developer     | Contact-TBD | *&lt;TBD*&gt; |
| RPC Framework developer   | Contact-TBD | *&lt;TBD*&gt; |
| Server/ Service Developer | Contact-TBD | *&lt;TBD*&gt; |

Architecture Constraints
========================

\todo TBD Architecture Constraints

System Scope and Context
========================
\todo System Scope and Context

Business Context
----------------
\todo Business Context

Technical Context
-----------------
\todo Technical Context

Solution Strategy
=================
\todo Solution Strategy

Building Block View
===================
\todo building block view

```plantuml
!include cc_rpc_overview_building_blocks.puml
```


```plantuml
!include cc_rpc_overview_client.puml
```



Runtime View 
============
\todo Runtime View

```plantuml
!include cc_rpc_call_sequence.puml
```


Deployment View 
===============
\todo Deployment View


Cross-cutting Concepts 
======================
\todo Cross-cutting Concepts 


Design Decisions 
================

### Decison  - Use C++ for RPC implementation

- efficient compiled language
- interfaces can be mapped to C (and from there to Java, Python etc.)

### Decison  - Use interface classes for RPC functionality

- for ease of use by application developer.
- more complex implementation compared to interface functions.

### Decision  - service and method as strings in RPC request and response

- for ease of use by application developer.
- could be shrinked to numeric identifier (use hashes or enumerations)


Quality Requirements 
====================
\todo Quality Requirements


Risks and Technical Debts 
=========================

### Risks 

**No final decision on transport layer.**

- mitigated for application and service developer by abstraction of transport in connection URI
- can not completely mitigated for RPC framework developer

**No requirements for response times**

- gather requirements

**No requirements for maximum size of request and response data**

- gather requirements

**Overabstraction of RPC framework** 

- review of framework implementation by software architect and other developers

### Technical Debt

- no detailed design
- currently only prototypical implementation
- endianness is not considered between server and client

Glossary 
========

| Term                              | Definition                        |
| --------------------------------- | --------------------------------- |
| RPC                               | Remote Procedure Call             |
| HTTP                              | Hypertext Transfer Protocol       |




