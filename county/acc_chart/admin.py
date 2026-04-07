from django.contrib import admin

from .models import Account, Niche, Segment

admin.site.register(Account)

admin.site.register(Segment)

admin.site.register(Niche)
