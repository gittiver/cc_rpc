# cc_rpc

As a sample for a software architecture documentation this repo contains 
the architecture and a prototypical implementation of the fictional cc_rpc framework.

We used cmake here as base for generating the documentation and also the implementation.

## Documentation

The architecture documentation content is based on the (arc42 template)[https://www.arc42.de/overview/].

For generating the documents we make use of doxygen and plantuml for generating the diagram images.
This allows html output and with the help of LaTEX a high quality and customizable pdf output.

Newer versions of doxygen allows markdown files as input, we make use of this feature here as 
the text based format allows easy review of document changes with the standard github functionality.
Least common denominator for editing of the documentation is a text editor and standard formats, 
this shall lower the entry for crewating and updating the documentation.

## Implementation 

for building the implementation we use also CMake as build system here.
The implementation is very basic as its purpose is only the show a prototypic realisation.

## Testing

for testing the implementation we make use of the catch2 library,
the implemented tests are just examples how to implement such tests,
they are nor complete or sufficinet for real world cases. 


