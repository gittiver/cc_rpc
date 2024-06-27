Architecture Description of the cc_rpc framework
================

[TOC] 

**Usage Note**

© We acknowledge that this document uses material from the arc 42
architecture template, <http://www.arc42.de>. Created by Dr. Peter
Hruschka & Dr. Gernot Starke.

Introduction and Goals
======================
\todo Introduction and Goals

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

**Contents.**

Any requirement that constrains software architects in their freedom of
design and implementation decisions or decision about the development
process. These constraints sometimes go beyond individual systems and
are valid for whole organizations and companies.

**Motivation.**

Architects should know exactly where they are free in their design
decisions and where they must adhere to constraints. Constraints must
always be dealt with; they may be negotiable, though.

**Form.**

Simple tables of constraints with explanations. If needed you can
subdivide them into technical constraints, organizational and political
constraints and conventions (e.g. programming or versioning guidelines,
documentation or naming conventions)


System Scope and Context
========================
\todo System Scope and Context

**Contents.**

System scope and context - as the name suggests - delimits your system
(i.e. your scope) from all its communication partners (neighboring
systems and users, i.e. the context of your system). It thereby
specifies the external interfaces.

If necessary, differentiate the business context (domain specific inputs
and outputs) from the technical context (channels, protocols, hardware).

**Motivation.**

The domain interfaces and technical interfaces to communication partners
are among your system’s most critical aspects. Make sure that you
completely understand them.

**Form.**

Various options:

-   Context diagrams

-   Lists of communication partners and their interfaces.

Business Context
----------------
\todo Business Context

**Contents.**

Specification of **all** communication partners (users, IT-systems, …)
with explanations of domain specific inputs and outputs or interfaces.
Optionally you can add domain specific formats or communication
protocols.

**Motivation.**

All stakeholders should understand which data are exchanged with the
environment of the system.

**Form.**

All kinds of diagrams that show the system as a black box and specify
the domain interfaces to communication partners.

Alternatively (or additionally) you can use a table. The title of the
table is the name of your system, the three columns contain the name of
the communication partner, the inputs, and the outputs.

**&lt;Diagram or Table&gt;**

**&lt;optionally: Explanation of external domain interfaces&gt;**

Technical Context
-----------------
\todo Technical Context
**Contents.**

Technical interfaces (channels and transmission media) linking your
system to its environment. In addition a mapping of domain specific
input/output to the channels, i.e. an explanation with I/O uses which
channel.

**Motivation.**

Many stakeholders make architectural decision based on the technical
interfaces between the system and its context. Especially infrastructure
or hardware designers decide these technical interfaces.

**Form.**

E.g. UML deployment diagram describing channels to neighboring systems,
together with a mapping table showing the relationships between channels
and input/output.

**&lt;Diagram or Table&gt;**

**&lt;optionally: Explanation of technical interfaces&gt;**

**&lt;Mapping Input/Output to Channels&gt;**

Solution Strategy
=================
\todo Solution Strategy

**Contents.**

A short summary and explanation of the fundamental decisions and
solution strategies, that shape the system’s architecture. These include

-   technology decisions

-   decisions about the top-level decomposition of the system, e.g.
    usage of an architectural pattern or design pattern

-   decisions on how to achieve key quality goals

-   relevant organizational decisions, e.g. selecting a development
    process or delegating certain tasks to third parties.

**Motivation.**

These decisions form the cornerstones for your architecture. They are
the basis for many other detailed decisions or implementation rules.

**Form.**

Keep the explanation of these key decisions short.

Motivate what you have decided and why you decided that way, based upon
your problem statement, the quality goals and key constraints. Refer to
details in the following sections.

Building Block View
===================
\todo building block view

**Content.**

The building block view shows the static decomposition of the system
into building blocks (modules, components, subsystems, classes,
interfaces, packages, libraries, frameworks, layers, partitions, tiers,
functions, macros, operations, datas structures, …) as well as their
dependencies (relationships, associations, …)

This view is mandatory for every architecture documentation. In analogy
to a house this is the *floor plan*.

**Motivation.**

Maintain an overview of your source code by making its structure
understandable through abstraction.

This allows you to communicate with your stakeholder on an abstract
level without disclosing implementation details.

**Form.**

The building block view is a hierarchical collection of black boxes and
white boxes (see figure below) and their descriptions.

![Hierarchy of building blocks](images/05_building_blocks-EN.png)

**Level 1** is the white box description of the overall system together
with black box descriptions of all contained building blocks.

**Level 2** zooms into some building blocks of level 1. Thus it contains
the white box description of selected building blocks of level 1,
together with black box descriptions of their internal building blocks.

**Level 3** zooms into selected building blocks of level 2, and so on.

Whitebox Overall System
-----------------------

Here you describe the decomposition of the overall system using the
following white box template. It contains

-   an overview diagram

-   a motivation for the decomposition

-   black box descriptions of the contained building blocks. For these
    we offer you alternatives:

    -   use *one* table for a short and pragmatic overview of all
        contained building blocks and their interfaces

    -   use a list of black box descriptions of the building blocks
        according to the black box template (see below). Depending on
        your choice of tool this list could be sub-chapters (in text
        files), sub-pages (in a Wiki) or nested elements (in a modeling
        tool).

-   (optional:) important interfaces, that are not explained in the
    black box templates of a building block, but are very important for
    understanding the white box. Since there are so many ways to specify
    interfaces why do not provide a specific template for them. In the
    worst case you have to specify and describe syntax, semantics,
    protocols, error handling, restrictions, versions, qualities,
    necessary compatibilities and many things more. In the best case you
    will get away with examples or simple signatures.

***&lt;Overview Diagram&gt;***

Motivation

:   *&lt;text explanation&gt;*

Contained Building Blocks

:   *&lt;Description of contained building block (black boxes)&gt;*

Important Interfaces

:   *&lt;Description of important interfaces&gt;*

Insert your explanations of black boxes from level 1:

If you use tabular form you will only describe your black boxes with
name and responsibility according to the following schema:

| **Name**             | **Responsibility**                           |
| -------------------- | -------------------------------------------- |
| Black Box 1          |  *&lt;Text&gt;*                              |
| Black Box 2          |  *&lt;Text&gt;*                              |

If you use a list of black box descriptions then you fill in a separate
black box template for every important building block . Its headline is
the name of the black box.

### &lt;Name black box 1&gt; 

Here you describe &lt;black box 1&gt; according the the following black
box template:

-   Purpose/Responsibility

-   Interface(s), when they are not extracted as separate paragraphs.
    This interfaces may include qualities and performance
    characteristics.

-   (Optional) Quality-/Performance characteristics of the black box,
    e.g.availability, run time behavior, ….

-   (Optional) directory/file location

-   (Optional) Fulfilled requirements (if you need traceability to
    requirements).

-   (Optional) Open issues/problems/risks

*&lt;Purpose/Responsibility&gt;*

*&lt;Interface(s)&gt;*

*&lt;(Optional) Quality/Performance Characteristics&gt;*

*&lt;(Optional) Directory/File Location&gt;*

*&lt;(Optional) Fulfilled Requirements&gt;*

*&lt;(optional) Open Issues/Problems/Risks&gt;*

### &lt;Name black box 2&gt; 

*&lt;black box template&gt;*

### &lt;Name black box n&gt; 

*&lt;black box template&gt;*

### &lt;Name interface 1&gt; 

…

### &lt;Name interface m&gt; 

Level 2 
-------

Here you can specify the inner structure of (some) building blocks from
level 1 as white boxes.

You have to decide which building blocks of your system are important
enough to justify such a detailed description. Please prefer relevance
over completeness. Specify important, surprising, risky, complex or
volatile building blocks. Leave out normal, simple, boring or
standardized parts of your system

### White Box *&lt;building block 1&gt;* 

…describes the internal structure of *building block 1*.

*&lt;white box template&gt;*

### White Box *&lt;building block 2&gt;* 

*&lt;white box template&gt;*

…

### White Box *&lt;building block m&gt;* 

*&lt;white box template&gt;*

Level 3 
-------

Here you can specify the inner structure of (some) building blocks from
level 2 as white boxes.

When you need more detailed levels of your architecture please copy this
part of arc42 for additional levels.

### White Box &lt;\_building block x.1\_&gt; 

Specifies the internal structure of *building block x.1*.

*&lt;white box template&gt;*

### White Box &lt;\_building block x.2\_&gt; 

*&lt;white box template&gt;*

### White Box &lt;\_building block y.1\_&gt; 

*&lt;white box template&gt;*

Runtime View 
============
\todo Runtime View

**Contents.**

The runtime view describes concrete behavior and interactions of the
system’s building blocks in form of scenarios from the following areas:

-   important use cases or features: how do building blocks execute
    them?

-   interactions at critical external interfaces: how do building blocks
    cooperate with users and neighboring systems?

-   operation and administration: launch, start-up, stop

-   error and exception scenarios

Remark: The main criterion for the choice of possible scenarios
(sequences, workflows) is their **architectural relevance**. It is
**not** important to describe a large number of scenarios. You should
rather document a representative selection.

**Motivation.**

You should understand how (instances of) building blocks of your system
perform their job and communicate at runtime. You will mainly capture
scenarios in your documentation to communicate your architecture to
stakeholders that are less willing or able to read and understand the
static models (building block view, deployment view).

**Form.**

There are many notations for describing scenarios, e.g.

-   numbered list of steps (in natural language)

-   activity diagrams or flow charts

-   sequence diagrams

-   BPMN or EPCs (event process chains)

-   state machines

-   …

&lt;Runtime Scenario 1&gt;
--------------------------

-   *&lt;insert runtime diagram or textual description of the
    scenario&gt;*

-   *&lt;insert description of the notable aspects of the interactions
    between the building block instances depicted in this diagram.&gt;*

&lt;Runtime Scenario 2&gt; 
--------------------------

… {#_}
-

&lt;Runtime Scenario n&gt; 
--------------------------

Deployment View 
===============
\todo Deployment View

**Content.**

The deployment view describes:

1.  the technical infrastructure used to execute your system, with
    infrastructure elements like geographical locations, environments,
    computers, processors, channels and net topologies as well as other
    infrastructure elements and

2.  the mapping of (software) building blocks to that infrastructure
    elements.

Often systems are executed in different environments, e.g. development
environment, test environment, production environment. In such cases you
should document all relevant environments.

Especially document the deployment view when your software is executed
as distributed system with more then one computer, processor, server or
container or when you design and construct your own hardware processors
and chips.

From a software perspective it is sufficient to capture those elements
of the infrastructure that are needed to show the deployment of your
building blocks. Hardware architects can go beyond that and describe the
infrastructure to any level of detail they need to capture.

**Motivation.**

Software does not run without hardware. This underlying infrastructure
can and will influence your system and/or some cross-cutting concepts.
Therefore, you need to know the infrastructure.

Maybe the highest level deployment diagram is already contained in
section 3.2. as technical context with your own infrastructure as ONE
black box. In this section you will zoom into this black box using
additional deployment diagrams:

-   UML offers deployment diagrams to express that view. Use it,
    probably with nested diagrams, when your infrastructure is more
    complex.

-   When your (hardware) stakeholders prefer other kinds of diagrams
    rather than the deployment diagram, let them use any kind that is
    able to show nodes and channels of the infrastructure.

Infrastructure Level 1 
----------------------

Describe (usually in a combination of diagrams, tables, and text):

-   the distribution of your system to multiple locations, environments,
    computers, processors, .. as well as the physical connections
    between them

-   important justification or motivation for this deployment structure

-   Quality and/or performance features of the infrastructure

-   the mapping of software artifacts to elements of the infrastructure

For multiple environments or alternative deployments please copy that
section of arc42 for all relevant environments.

***&lt;Overview Diagram&gt;***

Motivation

:   *&lt;explanation in text form&gt;*

Quality and/or Performance Features

:   *&lt;explanation in text form&gt;*

Mapping of Building Blocks to Infrastructure

:   *&lt;description of the mapping&gt;*

Infrastructure Level 2 
----------------------

Here you can include the internal structure of (some) infrastructure
elements from level 1.

Please copy the structure from level 1 for each selected element.

### *&lt;Infrastructure Element 1&gt;* 

*&lt;diagram + explanation&gt;*

### *&lt;Infrastructure Element 2&gt;* 

*&lt;diagram + explanation&gt;*

…

### *&lt;Infrastructure Element n&gt;* 

*&lt;diagram + explanation&gt;*

Cross-cutting Concepts 
======================
\todo Cross-cutting Concepts 

**Content.**

This section describes overall, principal regulations and solution ideas
that are relevant in multiple parts (= cross-cutting) of your system.
Such concepts are often related to multiple building blocks. They can
include many different topics, such as

-   domain models

-   architecture patterns or design patterns

-   rules for using specific technology

-   principal, often technical decisions of overall decisions

-   implementation rules

**Motivation.**

Concepts form the basis for *conceptual integrity* (consistency,
homogeneity) of the architecture. Thus, they are an important
contribution to achieve inner qualities of your system.

Some of these concepts cannot be assigned to individual building blocks
(e.g. security or safety). This is the place in the template that we
provided for a cohesive specification of such concepts.

**Form.**

The form can be varied:

-   concept papers with any kind of structure

-   cross-cutting model excerpts or scenarios using notations of the
    architecture views

-   sample implementations, especially for technical concepts

-   reference to typical usage of standard frameworks (e.g. using
    Hibernate for object/relational mapping)

**Structure.**

A potential (but not mandatory) structure for this section could be:

-   Domain concepts

-   User Experience concepts (UX)

-   Safety and security concepts

-   Architecture and design patterns

-   "Under-the-hood"

-   development concepts

-   operational concepts

Note: it might be difficult to assign individual concepts to one
specific topic on this list.

![Possible topics for crosscutting concepts](images/08-Crosscutting-Concepts-Structure-EN.png)

*&lt;Concept 1&gt;* 
-------------------

*&lt;explanation&gt;*

*&lt;Concept 2&gt;* 
-------------------

*&lt;explanation&gt;*

…

*&lt;Concept n&gt;* 
-------------------

*&lt;explanation&gt;*

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
**Content.**

This section contains all quality requirements as quality tree with
scenarios. The most important ones have already been described in
section 1.2. (quality goals)

Here you can also capture quality requirements with lesser priority,
which will not create high risks when they are not fully achieved.

**Motivation.**

Since quality requirements will have a lot of influence on architectural
decisions you should know for every stakeholder what is really important
to them, concrete and measurable.

Quality Tree 
------------

**Content.**

The quality tree (as defined in ATAM – Architecture Tradeoff Analysis
Method) with quality/evaluation scenarios as leafs.

**Motivation.**

The tree structure with priorities provides an overview for a sometimes
large number of quality requirements.

**Form.**

The quality tree is a high-level overview of the quality goals and
requirements:

-   tree-like refinement of the term "quality". Use "quality" or
    "usefulness" as a root

-   a mind map with quality categories as main branches

In any case the tree should include links to the scenarios of the
following section.

Quality Scenarios 
-----------------

**Contents.**

Concretization of (sometimes vague or implicit) quality requirements
using (quality) scenarios.

These scenarios describe what should happen when a stimulus arrives at
the system.

For architects, two kinds of scenarios are important:

-   Usage scenarios (also called application scenarios or use case
    scenarios) describe the system’s runtime reaction to a certain
    stimulus. This also includes scenarios that describe the system’s
    efficiency or performance. Example: The system reacts to a user’s
    request within one second.

-   Change scenarios describe a modification of the system or of its
    immediate environment. Example: Additional functionality is
    implemented or requirements for a quality attribute change.

**Motivation.**

Scenarios make quality requirements concrete and allow to more easily
measure or decide whether they are fulfilled.

Especially when you want to assess your architecture using methods like
ATAM you need to describe your quality goals (from section 1.2) more
precisely down to a level of scenarios that can be discussed and
evaluated.

**Form.**

Tabular or free form text.

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




