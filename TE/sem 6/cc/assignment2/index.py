import webapp2

class MainPage(webapp2.RequestHandler):
    def get(self):
        with open('./index.html', 'r') as f:
            self.response.write(f.read())


app = webapp2.WSGIApplication([('/', MainPage)], debug = True)