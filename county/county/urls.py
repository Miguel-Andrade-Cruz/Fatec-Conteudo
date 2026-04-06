from django.contrib import admin
from django.urls import include, path

urlpatterns = [
    path('plano/', include("acc_chart.urls")),
    path('fatos/', include("facts.urls")),
    path('admin/', admin.site.urls),
]
