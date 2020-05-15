# Web Application Firewall

* For protecting online services from sql injection, cross-site scripting(XXS).
* Identify threats which could degrade, compromise, or expose online applications to denial of service attacks.
* WAFs examine HTTP traffic before it reaches the application server.
* WAFs protect web applications from malicious endpoints and are essentially opposite to proxy-servers.
* To ensure security, WAFs intercept and examine all HTTP requests. Bogus traffic is simply blocked or tested with CAPTCHA tests designed to stump harmful bots and computer programs.
* Attacks that WAF prevent:
- Croos-side scripting: Attackers inject client-side scripts into web pages viewed by other users.
- SQL injection: Malicious code is inserted or injected into an web entry field that allows attackers to compromise the application and underlying systems.
- Cookie poisoning: Modification of a cookie to gain unauthorized information about the user for purposes such as identity theft.
- Unvalidated input — Attackers tamper with HTTP request (including the url, headers and form fields) to bypass the site’s security mechanisms.
- Layer 7 DoS — An HTTP flood attack that utilizes valid requests in typical URL data retrievals.
- Web scraping — Data scraping used for extracting data from websites.