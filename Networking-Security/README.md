Network Security
===============

In this challenge, we exploited a heartbleed-like bug in a server given to us in order to get the private key.

The private key we found is located in `key.txt`

The importance of a private key is that it is the "key" or cipher term that will encrypt a message. In the same way, this same private key is the cipher term that will be used to decrypt a message. If a 3rd party can access this key, they can read all communications between two secret parties. 

Our exploit works by asking the server to return more information than we sent it. For example, if we send the server "HELLO-5", the server will return the 5 characters sent to it, "HELLO". However, if we ask the server to do a call such as "HELLO-500", the server will, incorrectly, send us 500 characters: "HELLO2jfn29f...". This behavior is extremly dangerous, since anything that is loaded into the server's memory (for example, usernames and passwords, or in this case, the server's private key) will be sent back to the client. 
