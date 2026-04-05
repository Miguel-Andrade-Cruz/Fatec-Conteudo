from django.contrib import admin

from .models import AccPlan, Fact


class tab_accPlan_Admin(admin.ModelAdmin):
    pass


class tab_fact_Admin(admin.ModelAdmin):
    pass


admin.site.register(AccPlan, tab_accPlan_Admin)
admin.site.register(Fact, tab_fact_Admin)
